#!/bin/bash
INSTALL_DIR="/usr/bin"

echo "Installing mish"
cp ./mish "$INSTALL_DIR"

if ! grep -Fxq "$INSTALL_DIR/mish" /etc/shells; then
    echo "/usr/bin/mish" >> /etc/shells
fi