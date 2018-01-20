# libtinyclist
Tiny (nearly) dependency free linked list implementation in C

This linked list is held as small as possible and does only depend on a small part of the C standard library.
It handles memory all by itself and does not interfere with external objects.
On each append it allocates its own memory and copies the data.
This makes it possible to put stack objects into it without loosing them.
Removing elements or deleting the list guarantees to free all allocated space.
