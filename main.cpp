#include <iostream>
#include "unistd.h"
#include "shared_memory.h"

int main()
{
    bool uploadFlag = true;
    SharedMemory *sm;
    sm = new SharedMemory("SharedMemory");
    int i = 0;
    float f = 0.0;

    if ( uploadFlag )
    {
        sm->initSharedMemory(true);
        while(true)
        {
            sm->m_SharedSt.valueFloat = f;
            sm->m_SharedSt.value = i;

            if (!sm->setStruct())
                cout << "upload failed" << endl;

            cout << sm->m_SharedSt.value << "  " << sm->m_SharedSt.valueFloat << endl;
            i += 1;
            f += 1.11111;
            sleep(1);
        }
    } else {
        sm->initSharedMemory(false);
        while (true)
        {
            if (!sm->getStruct())
                cout << "download failed" << endl;
            cout << sm-> m_SharedSt.value << "   " << sm->m_SharedSt.valueFloat << endl;
            sleep(1);
        }
    }

    delete sm;
    return 0;
}

