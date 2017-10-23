/*************************************************************************
	> File Name: 6.cpp
	> Author: wk
	> Mail: 18402927708@163.com
	> Created Time: Mon 23 Oct 2017 08:20:19 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<string.h>
#include<queue>
using namespace std;



class Pet {
    public:
        Pet(string ty ="pet") {
         this->type = ty;
//         cout<<"pet construct\n";
        }
        ~Pet() {
 //        cout<<"pet distruct\n";
        }
        string GetPetType() {
          return this->type;
        }
    private:
        string type;
};


class Dog:public Pet {
    public:
        Dog():Pet("dog") { 
  //          cout<<"dog construct\n";
        }
        ~Dog() {
   //         cout<<"dog distruct\n";
        }
};

class Cat:public Pet {
    public:
        Cat():Pet("cat") { 
    //        cout<<"cat construct\n";
        }
        ~Cat() {
     //       cout<<"cat distruct\n";
        }
};

class PetEnter {
    public:
        PetEnter(Pet &pet,long count=0) {
            this->pet = pet;
            this->count = count;
        }
        long GetCount() {
           return this->count; 
        }
        Pet GetPet() {
           return this->pet; 
        }
        string GetPetType() {
           return this->pet.GetPetType(); 
        }
        void DecreCount() {
            this->count--;
        }
    private:
        Pet pet;
        long count; //其中一类pet的时间戳
};


class DogCatQueue {
    public:
        DogCatQueue(long count = 0){
            this->count = count; 
        }

        int add(Pet &pet)
        { 
            if (pet.GetPetType().compare("dog") == 0) {
                PetEnter *tmp1 =new PetEnter(pet,++(this->count));
                dogs.push(*tmp1);
            }
            if (pet.GetPetType().compare("cat") == 0) {
                PetEnter *tmp2 =new PetEnter(pet,++(this->count));
                cats.push(*tmp2);
            }

        }
        void pop_dog()
        {
            cout<<dogs.front().GetPetType().c_str()<<" "<<dogs.front().GetCount()<<endl; 
            dogs.pop();
        }
        void pop_cat()
        {
            cout<<cats.front().GetPetType().c_str()<<" "<<cats.front().GetCount()<<endl; 
            cats.pop();
        }
        void pop()
        {
            if(dogs.empty() && cats.empty()){
                return ; 
            } else if (dogs.empty()) {
                pop_cat(); 
            } else if (cats.empty()) {
                pop_dog(); 
            } else {
                if(dogs.front().GetCount() < cats.front().GetCount()) {
                    pop_dog(); 
                } else {
                    pop_cat(); 
                }
            }
        }
    private:
        queue<PetEnter> dogs; 
        queue<PetEnter> cats;
        long count; //所有pet的时间戳
};

int main()
{
    Cat cat;
    Dog dog;
    DogCatQueue dcq;
    dcq.add(dog);
    dcq.add(cat);
  //  dcq.pop_dog();
  //  dcq.pop_cat();

    dcq.pop();
    dcq.pop();
    dcq.pop();
    return 0;
    
}

