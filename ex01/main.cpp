#include "Serializer.hpp"
#include "data.hpp"

int main()
{
    Data data = {1, 2, 3};

    uintptr_t serialized = Serializer::serialize(&data);

    Data* deserialized = Serializer::deserialize(serialized);

    std::cout << "Deserialized data: " << deserialized->n1 << ", " << deserialized->n2 << ", " << deserialized->n3 << std::endl;

    if (deserialized == &data) {
        std::cout << "Pointer comparison successful" << std::endl;
        std::cout << deserialized << std::endl;
        std::cout << &data << std::endl;
        std::cout << data.n1 <<  std::endl;
        std::cout <<  data.n2 <<  std::endl;
        std::cout <<  data.n3 << std::endl;
    } else {
        std::cout << "Pointer comparison failed" << std::endl;
    }

    return 0;
}
