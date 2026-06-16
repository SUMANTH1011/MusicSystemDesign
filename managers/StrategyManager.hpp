#pragma once
#include<iostream>
#include "../strategies/SequentialPlayStrategy.hpp"
#include "../strategies/CustomQueueStrategy.hpp"
#include "../strategies/RandomPlayStrategy.hpp"
#include "../enums/StrategyType.hpp"

using namespace std;

class StrategyManager {
private:
    static StrategyManager* instance;
     SequentialPlayStrategy* sequentialStrategy;
    RandomPlayStrategy* randomStrategy;
    CustomQueueStrategy* customQueueStrategy;
    StrategyManager()
    {
        sequentialStrategy=new SequentialPlayStrategy();
        randomStrategy=new RandomPlayStrategy();
        customQueueStrategy=new CustomQueueStrategy();
    }
public:
    static StrategyManager* getInstance()
    {
        if(!instance)
        {
            instance=new StrategyManager();
        }
        return instance;
    }
    PlayStrategy* getStrategy(StrategyType type)
    {
            if(type==StrategyType::SEQUENTIAL)
                return sequentialStrategy;
            else if(type==StrategyType::RANDOM)
                return randomStrategy;
            else if(type==StrategyType::CUSTOM_QUEUE)
                return customQueueStrategy;
            else
                throw runtime_error("Invalid strategy type");
    }
};
StrategyManager* StrategyManager::instance=nullptr;