#!/bin/bash
# Set mish as a defualt shell

INSTALL_DIR="/usr/bin"

echo "Installing mish"

if [ -f "mish" ]; then
    cp ./mish "$INSTALL_DIR"

    if ! grep -Fxq "$INSTALL_DIR/mish" /etc/shells; then
        echo "$INSTALL_DIR/mish" >> /etc/shells
    fi
else
    echo "couldn't find executable"
fi