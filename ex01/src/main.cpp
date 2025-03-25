#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	Data data;
	data.id = 42;
	data.name = "John Doe";

	uintptr_t serialized = Serializer::serialize(&data);
	Data *deserialized = Serializer::deserialize(serialized);

	std::cout << "Original Data address: " << &data << std::endl;
	std::cout << "Serialized value: " << serialized << std::endl;
	std::cout << "Deserialized Data address: " << deserialized << std::endl;
	std::cout << std::endl;
	std::cout << "ID: " << deserialized->id << std::endl;
	std::cout << "Name: " << deserialized->name << std::endl;

	return 0;
}