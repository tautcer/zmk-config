#!/bin/bash
set -e

# Build the docker image
echo "Building Docker image..."
docker build -t zmk-config-builder .

# Ensure firmware directory exists
mkdir -p firmware

echo "Running build in Docker..."
# We mount the current directory to /workspace.
# We use --rm to clean up the container after run.

docker run --rm -it \
    -v "$(pwd):/workspace" \
    zmk-config-builder \
    /bin/bash -c "
        echo 'Checking yq version...'
        yq --version

        if [ ! -d .west ]; then
            echo 'Initializing West...'
            just init
        else
            echo 'Updating West...'
            just update
            # We need to re-run zephyr-export because the container environment (specifically ~/.cmake) is fresh
            west zephyr-export
        fi

        echo 'Patching zmk-auto-layer...'
        sed -i 's/zmk_keymap_layer_activate(auto_layer->layer, true);/zmk_keymap_layer_activate(auto_layer->layer);/g' modules/auto-layer/src/behaviors/behavior_auto_layer.c
        sed -i 's/zmk_keymap_layer_deactivate(auto_layer->layer, true);/zmk_keymap_layer_deactivate(auto_layer->layer);/g' modules/auto-layer/src/behaviors/behavior_auto_layer.c
        
        echo 'Building targets...'
        just build totem
    "
