#include "Serializer.hpp"

Serializer::~Serializer()
{
}

uintptr_t Serializer::serialize(Data * ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data * Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}
/* reinterpret_cast is a powerful and potentially unsafe type casting operator that allows you 
to convert between types that are unrelated, but it should be used with caution.*/

/* Purpose of reinterpret_cast:

 Pointer and Reference Conversions:
Used to convert one pointer type to another.
Used to convert one reference type to another.

Integral Type Conversions:
Used to convert integral types to pointer types.
Used to convert pointer types to integral types. */