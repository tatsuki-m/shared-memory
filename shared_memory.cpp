#include "shared_memory.h"

SharedMemory::SharedMemory(char *sharedMemoryName)
{
    strcpy(m_sharedMemoryName, sharedMemoryName);
    m_shm = NULL;
}

SharedMemory::~SharedMemory()
{
    if( m_shm != NULL)
        delete m_shm;
}

bool SharedMemory::initSharedMemory(bool deleteFlag)
{
    int m_size;
    m_size = sizeof(SharedSt) + 1024 * 10;
    cout << m_size << "Byte" << endl;

    if ( deleteFlag ) shared_memory_object::remove(m_sharedMemoryName);
    m_shm = new managed_shared_memory(open_or_create, m_sharedMemoryName, m_size);

    return true;
}

bool SharedMemory::setStruct()
{
    if ( m_shm == NULL )
        return false;
    interprocess_mutex* mx = m_shm->find_or_construct<interprocess_mutex>("TheMutext")();
    SharedSt* SharedMemoryPointer = m_shm->find_or_construct<SharedSt>("SharedSt")();

    scoped_lock<interprocess_mutex> *lock = new scoped_lock<interprocess_mutex>(*mx);
    memcpy(SharedMemoryPointer, &m_SharedSt, sizeof(SharedSt));

    delete lock;
    return true;
}

bool SharedMemory::getStruct()
{
    if( m_shm == NULL)
        return false;

    interprocess_mutex *mx = m_shm->find_or_construct<interprocess_mutex>("TheMutex")();
    SharedSt* SharedMemoryPointer = m_shm->find_or_construct<SharedSt>("SharedSt")();

    scoped_lock<interprocess_mutex> *lock = new scoped_lock<interprocess_mutex>(*mx);
    memcpy( &m_SharedSt, SharedMemoryPointer, sizeof(SharedSt));

    delete lock;
    return true;
}

