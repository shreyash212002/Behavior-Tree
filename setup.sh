#!/bin/bash

# Robot Behavior Tree Setup Script
# This script automates the installation and setup process

set -e  # Exit on any error

echo "=== Robot Behavior Tree Project Setup ==="
echo ""

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

print_status() {
    echo -e "${GREEN}[INFO]${NC} $1"
}

print_warning() {
    echo -e "${YELLOW}[WARNING]${NC} $1"
}

print_error() {
    echo -e "${RED}[ERROR]${NC} $1"
}

# Check if running on Ubuntu/Debian
if ! command -v apt &> /dev/null; then
    print_error "This script is designed for Ubuntu/Debian systems with apt package manager"
    exit 1
fi

print_status "Updating package list..."
sudo apt update

print_status "Installing build dependencies..."
sudo apt install -y build-essential cmake git pkg-config

print_status "Installing BehaviorTree.CPP dependencies..."
sudo apt install -y libzmq3-dev libboost-dev

# Check if BehaviorTree.CPP is already installed
if pkg-config --exists behaviortree_cpp; then
    print_status "BehaviorTree.CPP is already installed"
else
    print_status "BehaviorTree.CPP not found. Installing from source..."
    
    # Create temporary directory
    TEMP_DIR=$(mktemp -d)
    cd $TEMP_DIR
    
    print_status "Cloning BehaviorTree.CPP repository..."
    git clone https://github.com/BehaviorTree/BehaviorTree.CPP.git
    cd BehaviorTree.CPP
    
    print_status "Building BehaviorTree.CPP..."
    mkdir build && cd build
    cmake ..
    make -j$(nproc)
    
    print_status "Installing BehaviorTree.CPP system-wide..."
    sudo make install
    sudo ldconfig
    
    # Clean up
    cd ~
    rm -rf $TEMP_DIR
    
    print_status "BehaviorTree.CPP installation completed"
fi

# Create project directory
PROJECT_DIR="$HOME/robot_behavior_tree_project"
print_status "Creating project directory: $PROJECT_DIR"
mkdir -p "$PROJECT_DIR"

print_status "Project setup completed successfully!"
echo ""
echo "Next steps:"
echo "1. Copy your project files (robot_behavior_tree.cpp, robot_behavior_tree.xml, CMakeLists.txt) to:"
echo "   $PROJECT_DIR"
echo ""
echo "2. Build the project:"
echo "   cd $PROJECT_DIR"
echo "   mkdir build && cd build"
echo "   cmake .."
echo "   make"
echo ""
echo "3. Run the behavior tree:"
echo "   cp ../robot_behavior_tree.xml ."
echo "   ./robot_behavior_tree"
echo ""
print_status "Setup script completed successfully!"