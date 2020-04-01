# Smart Pointers

Smart pointer is basically a template class that uses operator overloads to provide the functionality of a pointer.  
While providing additional features to support improved memory management and safety.  
A smart pointer is essentially a wrapper around a standard bare C-langauge pointer.  
It is designed to provide these benefits while operating as closely as possible to a standard pointer.  

Smart pointers are in `#include <memory>` header.

**Unique Pointer**
- Only one copy of this pointer
- Cannot be copied
- Can be safely destroy its associated resources by calling reset on the pointer
- Can transfer ownership by moving it

**Shared Pointer**
- Can make copies of this pointer
- Can delete those copies as much as I want
- The resources will automatically and safely be destroyed when all copies of pointers are deleted or when it goes out of scope

**Weak Pointer**
- Weak pointer is used to prevent circular references
- Weak pointer goes out of scope when its share pointers gets deleted