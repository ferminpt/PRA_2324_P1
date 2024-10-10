#include "List.h"
#include<stdexcept>
#include<ostream>

template <typename T>
class ListArray : public List<T>{
	private:
T* array;
int max;
int n;
static const int MINISIZE;

void resize(int new_size){
	T* newArray=new T[new_size];
	for (int i = 0; i < n; ++i) {
            newArray[i] = array[i];
        }
delete[] array;
array =newArray;
max= new_size;
}

	public:
ListArray(){
	array=new T[MINISIZE];
	max= MINISIZE;
	n =0;
}

~ListArray() {
        delete[] array;      
}

T operator[](int pos){
	if(pos <0 || pos > n){
		throw std::out_of_range("La posición no es correcta");
}
else{
	return array[pos];
}
};
//std::ostream& operator<<(std::ostream& out, const ListArray<T>& list) {
  //out << "[";
    //    for (int i = 0; i < list.n; ++i) {
      //      out << list.array[i];
        //    if (i < list.n - 1) {
          //      out << ", ";
           // }
        //}
        //out << "]";
       // return out;
   // }

