#include "MyOpenAddressing.hpp"

int main() {

    MyOpenAddressHashTable myOpenAddressHashTable(10);
    
    myOpenAddressHashTable.set("TEST","this is test");
    myOpenAddressHashTable.set("TEST1","this is test1");
    myOpenAddressHashTable.set("TEST2","this is test2");
    myOpenAddressHashTable.set("TEST3","this is test3");
    myOpenAddressHashTable.set("TEST4","this is test4");
    myOpenAddressHashTable.set("TEST5","this is test5");
    myOpenAddressHashTable.set("TEST6","this is test6");
    myOpenAddressHashTable.set("TEST7","this is test7");
    myOpenAddressHashTable.set("TEST8","this is test8");
    myOpenAddressHashTable.set("TEST9","this is test9");

    myOpenAddressHashTable.get("TEST7");

    myOpenAddressHashTable.showAll();

    return 0;
}