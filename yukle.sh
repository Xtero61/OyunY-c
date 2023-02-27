#!/usr/bin/env bash

echo "Gerekli paketler arch icin yukleniyor."
sudo pacman --noconfirm -S clang   \
                           lldb    \
                           scons   \
                           raylib  \
                           vscode  \
