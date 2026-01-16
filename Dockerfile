FROM zmkfirmware/zmk-build-arm:stable

# Install just, jq, and python-pip to get yq 3.4.3
RUN apt-get update && apt-get install -y wget curl jq python3-pip \
    && curl --proto '=https' --tlsv1.2 -sSf https://just.systems/install.sh | bash -s -- --to /usr/bin \
    && pip3 install --break-system-packages yq==3.4.3 \
    && apt-get clean && rm -rf /var/lib/apt/lists/*

WORKDIR /workspace
