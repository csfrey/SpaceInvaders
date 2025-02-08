#!/bin/bash

echo "🔧 Setting up Space Invaders development environment for macOS..."

# Ensure Homebrew is installed
if ! command -v brew &>/dev/null; then
    echo "❌ Homebrew is not installed. Installing it now..."
    /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
fi

# Install Raylib
if ! brew list raylib &>/dev/null; then
    echo "📦 Installing Raylib..."
    brew install raylib
else
    echo "✅ Raylib is already installed."
fi

echo "✅ Setup complete! Run 'make run' to start the game."
