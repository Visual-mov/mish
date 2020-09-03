#!/bin/bash

# Script to set mish as a default shell

INSTALL_DIR="/usr/bin"

echo "Installing mish"

if [ -f "mish" ]; then
    cp ./mish "$INSTALL_DIR"

    if ! grep -Fxq "$INSTALL_DIR/mish" /etc/shells; then
        echo "$INSTALL_DIR/mish" >> /etc/shells
    fi

    # add chsh -s

else
    echo "Couldn't find executable, error compiling?"
fi