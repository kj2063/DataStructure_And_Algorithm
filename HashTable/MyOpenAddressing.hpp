#include <iostream>

using namespace std;

enum elementStatus {
    EMPTY = 0,
    USED = 1
};

struct tagNode {
    string key;
    string strData;

    enum elementStatus status;

    tagNode():status{EMPTY}{};
    tagNode(string key, string strData):key{key},strData{strData},status{USED}{};
    ~tagNode(){};
};

class MyOpenAddressHashTable {
    private:
        tagNode *tagNodeArr;
        int tableSize;
        int usedSize;

    public:
        MyOpenAddressHashTable(int tableSize){
            tagNodeArr = new tagNode[tableSize];
            this->tableSize = tableSize;
            usedSize = 0;
        };
        ~MyOpenAddressHashTable(){};
        void showAll();
        void set(string keyParam, string strDataParam);
        string get(string keyParam);
        int hash1(string keyParam);
        int hash2(string keyParam);
        void reHash();
};

void MyOpenAddressHashTable::showAll(){
    for(int i=0; i<tableSize; i++){
        cout << "key : " << tagNodeArr[i].key << " / data : " << tagNodeArr[i].strData << " / index : " << i << endl;
    }
}

void MyOpenAddressHashTable::set(string keyParam, string strDataParam){
    double usage = (double)this->usedSize/(double)this->tableSize;
    cout << this->usedSize << "/" << this->tableSize << " => " << usage << endl;
    if(usage > 0.75){
        reHash();
    }

    int keyParamLength = keyParam.length();
    int address = hash1(keyParam);
    int stepSize = hash2(keyParam);

    while(this->tagNodeArr[address].status != EMPTY && 
            this->tagNodeArr[address].key.compare(keyParam) != 0){
        
        address = (address + stepSize)%this->tableSize;
        
    }

    this->tagNodeArr[address].key = keyParam;
    this->tagNodeArr[address].strData = strDataParam;
    this->tagNodeArr[address].status = USED;
    this->usedSize = this->usedSize + 1;
}

string MyOpenAddressHashTable::get(string keyParam){
    int keyParamLength = keyParam.length();
    int address = hash1(keyParam);
    int stepSize = hash2(keyParam);
    
    while(this->tagNodeArr[address].status != EMPTY && 
            this->tagNodeArr[address].key.compare(keyParam) != 0){
        
        address = (address + stepSize)%this->tableSize;
        
    }

    cout << "result : " << this->tagNodeArr[address].strData << endl;

    return this->tagNodeArr[address].strData;
}

int MyOpenAddressHashTable::hash1(string keyParam){
    int hashValue = 0;

    for(int i=0; i<keyParam.length() ; i++){
        //use bitwise operators to make all arrays available.
        hashValue = (hashValue << 3) + keyParam[i];
    }

    hashValue = hashValue % this->tableSize;

    return hashValue;
}

int MyOpenAddressHashTable::hash2(string keyParam){
    int hashValue = 0;

    for(int i=0; i<keyParam.length() ; i++){
        hashValue = (hashValue << 5) + keyParam[i];
    }

    hashValue = hashValue % (this->tableSize + 2);

    return hashValue;
}

void MyOpenAddressHashTable::reHash(){
    tagNode *oldTagNodeArr = this->tagNodeArr;
    int oldTableSize = this->tableSize;

    this->tableSize = this->tableSize * 2;
    this->tagNodeArr = new tagNode[this->tableSize];
    this->usedSize = 0;
    
    for(int i=0; i<oldTableSize; i++){
        if(oldTagNodeArr[i].status == USED){
            set(oldTagNodeArr[i].key, oldTagNodeArr[i].strData);
        }
    }

    delete[] oldTagNodeArr;
}