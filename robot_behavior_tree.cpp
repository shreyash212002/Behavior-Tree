#include <behaviortree_cpp/bt_factory.h>
#include <behaviortree_cpp/tree_node.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <filesystem>

using namespace BT;

// Condition Node Classes
class IsDoorClosed : public BT::ConditionNode
{
public:
    IsDoorClosed(const std::string& name, const BT::NodeConfiguration& config)
        : BT::ConditionNode(name, config) {}

    static BT::PortsList providedPorts()
    {
        return {};
    }

    BT::NodeStatus tick() override
    {
        std::cout << "Checking if room door is closed..." << std::endl;
        // Simulate door being closed (you can change this for testing)
        bool door_closed = true;
        if (door_closed)
        {
            std::cout << "Room door is closed" << std::endl;
            return BT::NodeStatus::SUCCESS;
        }
        else
        {
            std::cout << "Room door is open" << std::endl;
            return BT::NodeStatus::FAILURE;
        }
    }
};

class IsFridgeDoorClosed : public BT::ConditionNode
{
public:
    IsFridgeDoorClosed(const std::string& name, const BT::NodeConfiguration& config)
        : BT::ConditionNode(name, config) {}

    static BT::PortsList providedPorts()
    {
        return {};
    }

    BT::NodeStatus tick() override
    {
        std::cout << "Checking if fridge door is closed..." << std::endl;
        // Simulate fridge door being closed (you can change this for testing)
        bool fridge_door_closed = true;
        if (fridge_door_closed)
        {
            std::cout << "Fridge door is closed" << std::endl;
            return BT::NodeStatus::SUCCESS;
        }
        else
        {
            std::cout << "Fridge door is open" << std::endl;
            return BT::NodeStatus::FAILURE;
        }
    }
};

// Action Node Classes
class MoveTowardsDoor : public BT::SyncActionNode
{
public:
    MoveTowardsDoor(const std::string& name, const BT::NodeConfiguration& config)
        : BT::SyncActionNode(name, config) {}

    static BT::PortsList providedPorts()
    {
        return {};
    }

    BT::NodeStatus tick() override
    {
        std::cout << "Moving towards the room door..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::cout << "Reached the room door" << std::endl;
        return BT::NodeStatus::SUCCESS;
    }
};

class OpenDoor : public BT::SyncActionNode
{
public:
    OpenDoor(const std::string& name, const BT::NodeConfiguration& config)
        : BT::SyncActionNode(name, config) {}

    static BT::PortsList providedPorts()
    {
        return {};
    }

    BT::NodeStatus tick() override
    {
        std::cout << "Opening the room door..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::cout << "Room door opened successfully" << std::endl;
        return BT::NodeStatus::SUCCESS;
    }
};

class EnterRoom : public BT::SyncActionNode
{
public:
    EnterRoom(const std::string& name, const BT::NodeConfiguration& config)
        : BT::SyncActionNode(name, config) {}

    static BT::PortsList providedPorts()
    {
        return {};
    }

    BT::NodeStatus tick() override
    {
        std::cout << "Entering the room..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(800));
        std::cout << "Successfully entered the room" << std::endl;
        return BT::NodeStatus::SUCCESS;
    }
};

class MoveTowardsFridge : public BT::SyncActionNode
{
public:
    MoveTowardsFridge(const std::string& name, const BT::NodeConfiguration& config)
        : BT::SyncActionNode(name, config) {}

    static BT::PortsList providedPorts()
    {
        return {};
    }

    BT::NodeStatus tick() override
    {
        std::cout << "Moving towards the fridge..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::cout << "Reached the fridge" << std::endl;
        return BT::NodeStatus::SUCCESS;
    }
};

class OpenFridgeDoor : public BT::SyncActionNode
{
public:
    OpenFridgeDoor(const std::string& name, const BT::NodeConfiguration& config)
        : BT::SyncActionNode(name, config) {}

    static BT::PortsList providedPorts()
    {
        return {};
    }

    BT::NodeStatus tick() override
    {
        std::cout << "Opening the fridge door..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::cout << "Fridge door opened successfully" << std::endl;
        return BT::NodeStatus::SUCCESS;
    }
};

class FindApple : public BT::SyncActionNode
{
public:
    FindApple(const std::string& name, const BT::NodeConfiguration& config)
        : BT::SyncActionNode(name, config) {}

    static BT::PortsList providedPorts()
    {
        return {};
    }

    BT::NodeStatus tick() override
    {
        std::cout << "Looking for an apple in the fridge..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1500));
        std::cout << "Found an apple!" << std::endl;
        return BT::NodeStatus::SUCCESS;
    }
};

class PickApple : public BT::SyncActionNode
{
public:
    PickApple(const std::string& name, const BT::NodeConfiguration& config)
        : BT::SyncActionNode(name, config) {}

    static BT::PortsList providedPorts()
    {
        return {};
    }

    BT::NodeStatus tick() override
    {
        std::cout << "Picking up the apple..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1200));
        std::cout << "Apple picked successfully!" << std::endl;
        return BT::NodeStatus::SUCCESS;
    }
};

class CloseFridgeDoor : public BT::SyncActionNode
{
public:
    CloseFridgeDoor(const std::string& name, const BT::NodeConfiguration& config)
        : BT::SyncActionNode(name, config) {}

    static BT::PortsList providedPorts()
    {
        return {};
    }

    BT::NodeStatus tick() override
    {
        std::cout << "Closing the fridge door..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::cout << "Fridge door closed" << std::endl;
        return BT::NodeStatus::SUCCESS;
    }
};

class MoveTowardsRoomExit : public BT::SyncActionNode
{
public:
    MoveTowardsRoomExit(const std::string& name, const BT::NodeConfiguration& config)
        : BT::SyncActionNode(name, config) {}

    static BT::PortsList providedPorts()
    {
        return {};
    }

    BT::NodeStatus tick() override
    {
        std::cout << "Moving towards the room exit..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::cout << "Reached the room exit" << std::endl;
        return BT::NodeStatus::SUCCESS;
    }
};

class ExitRoom : public BT::SyncActionNode
{
public:
    ExitRoom(const std::string& name, const BT::NodeConfiguration& config)
        : BT::SyncActionNode(name, config) {}

    static BT::PortsList providedPorts()
    {
        return {};
    }

    BT::NodeStatus tick() override
    {
        std::cout << "Exiting the room..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(800));
        std::cout << "Successfully exited the room" << std::endl;
        return BT::NodeStatus::SUCCESS;
    }
};

class CloseRoomDoor : public BT::SyncActionNode
{
public:
    CloseRoomDoor(const std::string& name, const BT::NodeConfiguration& config)
        : BT::SyncActionNode(name, config) {}

    static BT::PortsList providedPorts()
    {
        return {};
    }

    BT::NodeStatus tick() override
    {
        std::cout << "Closing the room door..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::cout << "Room door closed" << std::endl;
        return BT::NodeStatus::SUCCESS;
    }
};

int main()
{
    std::cout << "=== Robot Apple Fetching Behavior Tree Demo ===" << std::endl;
    std::cout << "Starting robot behavior tree execution..." << std::endl;

    // Create behavior tree factory
    BT::BehaviorTreeFactory factory;

    // Register all condition nodes
    factory.registerNodeType<IsDoorClosed>("IsDoorClosed");
    factory.registerNodeType<IsFridgeDoorClosed>("IsFridgeDoorClosed");

    // Register all action nodes
    factory.registerNodeType<MoveTowardsDoor>("MoveTowardsDoor");
    factory.registerNodeType<OpenDoor>("OpenDoor");
    factory.registerNodeType<EnterRoom>("EnterRoom");
    factory.registerNodeType<MoveTowardsFridge>("MoveTowardsFridge");
    factory.registerNodeType<OpenFridgeDoor>("OpenFridgeDoor");
    factory.registerNodeType<FindApple>("FindApple");
    factory.registerNodeType<PickApple>("PickApple");
    factory.registerNodeType<CloseFridgeDoor>("CloseFridgeDoor");
    factory.registerNodeType<MoveTowardsRoomExit>("MoveTowardsRoomExit");
    factory.registerNodeType<ExitRoom>("ExitRoom");
    factory.registerNodeType<CloseRoomDoor>("CloseRoomDoor");

    // Load behavior tree from XML file
    try
    {
        const std::filesystem::path xml_file = std::filesystem::absolute("robot_behavior_tree.xml");
        auto tree = factory.createTreeFromFile(xml_file);
        
        std::cout << "\nBehavior tree loaded successfully!" << std::endl;
        std::cout << "Executing behavior tree...\n" << std::endl;

        // Execute the behavior tree
        BT::NodeStatus status = tree.tickWhileRunning();

        std::cout << "\n=== Behavior Tree Execution Completed ===" << std::endl;
        
        if (status == BT::NodeStatus::SUCCESS)
        {
            std::cout << "Mission accomplished! Robot successfully fetched the apple." << std::endl;
        }
        else if (status == BT::NodeStatus::FAILURE)
        {
            std::cout << "Mission failed. Robot could not complete the task." << std::endl;
        }
        else
        {
            std::cout << "Mission status: RUNNING (unexpected termination)" << std::endl;
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return -1;
    }

    return 0;
}