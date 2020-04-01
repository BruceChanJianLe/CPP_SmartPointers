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

## Summary
C++ provides three different types of smart pointers, unique pointer, shared pointer and weak pointer.  
So, how do I choose which one to use in a given situation?  
My strategy is to start with a default choice and specialize from there.  
For most purposes, I'll choose a shared pointer by default.  
It's powerful and flexible, while still being safe.  
This is the pointer that works most like unmanaged pointer, but it still manages objects nicely.  
I'll choose a weak pointer for circumstances where I need an optional value, that is, I don't require a pointer to be valid.  
I just need to know if it is or it isn't valid.  
This is useful for breaking up circular references, but it's also useful for other cases where I need to link to a resource that's managed by another object.  
Finally, I'll choose a unique pointer in cases where I need to know that a resource is only available to one object at a time.  
This is a one to one relationship.  
A unique pointer cannot be copied.  
This is actually a bit deceptive because you can take an L reference of a unique pointer.  
Because of this, some developers like to use the unique pointer as their default choice and only use the shared pointer where it's necessary to actually share the pointer.  
You may certainly do that if you like.  
It's really a matter of style.  
For my part, I like the explicit nature of the shared pointer, rather the implicit of using a unique pointer with L references.  
This is my strategy and you're welcome to use it as a starting point.  
I strongly suggest that you spend some time working with the different types of smart pointers.  
Then, you'll develop a strategy that works for you.
