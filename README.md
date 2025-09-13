# Robot Behavior Tree Project

This project implements a behavior tree for a robot that navigates to enter a room, opens a fridge, picks an apple, and exits the room using the BehaviorTree.CPP library.

## Project Structure

```
robot_behavior_tree/
├── robot_behavior_tree.cpp    # Main C++ implementation with all node classes
├── robot_behavior_tree.xml    # XML behavior tree definition
├── CMakeLists.txt             # CMake build configuration
└── README.md                  # This file
```

## Prerequisites

- **Ubuntu 20.04 or later** (recommended)
- **C++17 compatible compiler** (GCC 9+ or Clang 10+)
- **CMake 3.16+**
- **Git**

## Installation Instructions

### Step 1: Install Dependencies

```bash
# Update package list
sudo apt update

# Install build tools
sudo apt install build-essential cmake git

# Install BehaviorTree.CPP dependencies
sudo apt install libzmq3-dev libboost-dev
```

### Step 2: Install BehaviorTree.CPP Library

**Option A: Install from Ubuntu Package (Recommended)**
```bash
# For ROS users (if you have ROS installed)
sudo apt install ros-$(lsb_release -cs)-behaviortree-cpp-v3

# For non-ROS users, use vcpkg or build from source (see Option B)
```

**Option B: Build from Source**
```bash
# Clone the BehaviorTree.CPP repository
git clone https://github.com/BehaviorTree/BehaviorTree.CPP.git
cd BehaviorTree.CPP

# Create build directory
mkdir build && cd build

# Configure and build
cmake ..
make -j$(nproc)

# Install system-wide
sudo make install

# Update library cache
sudo ldconfig
```

**Option C: Using Conan Package Manager**
```bash
# Install Conan first
pip install conan

# In your project directory
conan profile detect --force
conan install . -of build_release -s build_type=Release
```

### Step 3: Setup Project Directory

```bash
# Create project directory
mkdir -p ~/robot_behavior_tree_project
cd ~/robot_behavior_tree_project

# Copy the provided files to this directory:
# - robot_behavior_tree.cpp
# - robot_behavior_tree.xml
# - CMakeLists.txt
```

### Step 4: Build the Project

```bash
# In your project directory
mkdir build && cd build

# Configure with CMake
cmake ..

# Build the project
make

# Alternative: Build with more verbose output
make VERBOSE=1
```

### Step 5: Run the Behavior Tree

```bash
# Make sure you're in the build directory
cd build

# Copy XML file to build directory (or adjust path in code)
cp ../robot_behavior_tree.xml .

# Run the executable
./robot_behavior_tree
```

## Behavior Tree Flow

The robot follows this sequence of actions:

1. **Move towards room door**
2. **Check if door is closed** → **Open door if needed**
3. **Enter the room**
4. **Move towards fridge**
5. **Check if fridge door is closed** → **Open fridge door if needed**
6. **Find apple in fridge**
7. **Pick the apple**
8. **Close fridge door**
9. **Move towards room exit**
10. **Exit the room**
11. **Close room door**

## Node Types Implemented

### Condition Nodes
- `IsDoorClosed`: Checks if the room door is closed
- `IsFridgeDoorClosed`: Checks if the fridge door is closed

### Action Nodes
- `MoveTowardsDoor`: Navigate to the room door
- `OpenDoor`: Open the room door
- `EnterRoom`: Enter the room
- `MoveTowardsFridge`: Navigate to the fridge
- `OpenFridgeDoor`: Open the fridge door
- `FindApple`: Look for an apple in the fridge
- `PickApple`: Pick up the apple
- `CloseFridgeDoor`: Close the fridge door
- `MoveTowardsRoomExit`: Navigate to room exit
- `ExitRoom`: Exit the room
- `CloseRoomDoor`: Close the room door

## Control Flow Nodes Used
- **Sequence**: Execute children in order, succeed if all succeed
- **Fallback**: Try children until one succeeds
- **Inverter**: Invert SUCCESS/FAILURE of child node

## Troubleshooting

### Common Issues

1. **"behaviortree_cpp not found" error**
   ```bash
   # Make sure the library is installed and findable
   pkg-config --cflags --libs behaviortree_cpp
   
   # If using custom install location, set CMAKE_PREFIX_PATH
   export CMAKE_PREFIX_PATH=/path/to/install:$CMAKE_PREFIX_PATH
   ```

2. **Compilation errors**
   ```bash
   # Check C++ standard
   g++ --version
   
   # Ensure C++17 support
   export CXX_FLAGS="-std=c++17"
   ```

3. **Runtime XML file not found**
   ```bash
   # Make sure XML file is in the same directory as executable
   # Or provide absolute path in the code
   ```

### Testing Different Scenarios

You can modify the boolean values in the condition nodes to test different scenarios:

```cpp
// In IsDoorClosed::tick()
bool door_closed = false;  // Change to false to test door opening

// In IsFridgeDoorClosed::tick()  
bool fridge_door_closed = false;  // Change to false to test fridge opening
```

## Expected Output

When running successfully, you should see output like:
```
=== Robot Apple Fetching Behavior Tree Demo ===
Starting robot behavior tree execution...

Behavior tree loaded successfully!
Executing behavior tree...

Moving towards the room door...
Reached the room door
Checking if room door is closed...
Room door is closed
Opening the room door...
Room door opened successfully
Entering the room...
Successfully entered the room
Moving towards the fridge...
Reached the fridge
Checking if fridge door is closed...
Fridge door is closed
Opening the fridge door...
Fridge door opened successfully
Looking for an apple in the fridge...
Found an apple!
Picking up the apple...
Apple picked successfully!
Closing the fridge door...
Fridge door closed
Moving towards the room exit...
Reached the room exit
Exiting the room...
Successfully exited the room
Closing the room door...
Room door closed

=== Behavior Tree Execution Completed ===
Mission accomplished! Robot successfully fetched the apple.
```

## Additional Resources

- [BehaviorTree.CPP Documentation](https://www.behaviortree.dev/)
- [BehaviorTree.CPP GitHub](https://github.com/BehaviorTree/BehaviorTree.CPP)
- [Tutorial Videos](https://www.youtube.com/watch?v=4PUiDmD5dkg)

## License

This project is provided as an educational example. The BehaviorTree.CPP library is licensed under the MIT License.