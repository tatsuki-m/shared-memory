#include <iostream>

// shared memory
#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/containers/vector.hpp>
#include <boost/interprocess/allocators/allocator.hpp>

// mutex
#include <boost/interprocess/sync/interprocess_mutex.hpp>
#include <boost/interprocess/sync/interprocess_mutex.hpp>

using namespace std;
using namespace boost::interprocess;

class SharedMemory
{
    struct SharedSt
    {
        int value;
        double valueFloat;
    };

    managed_shared_memory *m_shm;
    char m_sharedMemoryName[32];

public:
      SharedSt m_SharedSt;

      SharedMemory(char *sharedMemoryName);
      ~SharedMemory();
      bool initSharedMemory(bool deleteFlag);
      bool setStruct();
      bool getStruct();
};

