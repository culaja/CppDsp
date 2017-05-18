# Complex number streaming
# Task
A data source generates a continuous stream of data packets of varying leng . These are to be passed through a processor that requires fixed-length blocks. The data is in the form of a sequence of complex numbers encoded as a pair of float values.

Write a class that accepts variable length packets, generates fixed length packets and passes these to an internal 'process' method. No assumptions should be made about the sizes or relative sizes of the packets to be processed or the size of packets arriving.

The code should be clean, well structured and internally documented. Where not obvious from the code, the comments should explain the theory of operation.
# Architecture
System consists of three fundamental components:
    - PacketQueue - queue that can accept packets of any length and that supports reading of fixed length packets (supports buffering).
    - Producer - Thread that generates the packets using FloatNumberSequenceGenerator and pushes generates packets to the previously mentioned PacketQueue.
    - Consumer - Thread that waits for fixed length packet from the PacketQueue and dispatches the packet to the PacketProcessor
 
Component collaboration is presented in picture below:
![alt text](https://github.com/culaja/CppDsp/blob/master/Architecture.png)

# Design
Some of the classes can be seen from Architecture picture. I've tried to follow SOLID principles, so you can find here a lot of interfaces (or abstract classes) and their implementations. For example generator is an interface where we can replace its implementation with any other packet generator implementation that suits our needs. The same states for processor (currently implemented processor is just a simple method that iterates through all complex numbers and prints them).

Main business logic of the application is in PacketQueue class. There is placed entire logic around packet buffering and logic around eventing (producer have to send notification to the consumer to avoid unnecessary polling).

Application entry point is in MainTestHarness class that creates producer and consumer threads and binds them with the one and only PacketQueue object. It is nice to mention that IOC (Inversion of Control) design principle is used when PacketQueue object is created (here we can easily replace the generator or processor by using another implementation or we can say another strategy). This class can be further refactored and core business logic can be moved to separate class, but this is enough for a proof of concept solution.

In order to implement Producer/Consumer concept we must have some kind of synchronization between the threads, thus I introduced utility classes for Mutex and Event (just a wrapper around cpp 14 std classes).

I tried to write self-explaining code without too many comments. This is possible to achieve if you follow Single responsibility principle and have many private methods. I think the code is readable.

# Potential enhancements
This is just a proof of concept example and the solution can be further improved:
- Performances can be improved by implementing a different PacketQueue. Currently, we use std::queue<float> for storing items, where we need to iterate through each item. This can be replaced with different approach where memcopy can be used (or same STL derivative of memcopy: std::vector::insert for example).
- Packet class is now immutable class. This will always create a new object. This can be improved by using the same object over and over again in same places and avoiding unnecessary calling of copy constructor. This would probably introduce some smart pointers...
- Solution can be completely rewritten using TDD approach. I think different design would emerge because some tests can be easier implemented with simpler design. I didn't use TDD since I'm not fluent in C++ right now. I would also follow the "functional core, imperative shell" approach that would for sure provide better testing of business logic. (link: https://www.destroyallsoftware.com/screencasts/catalog/functional-core-imperative-shell).

# Conclusion
Priority of this solution was to have better code design. I wanted to show how some design principles and patterns can be used to enable unit testing and easier maintainability (SOLID principles). Unfortunately, this has deteriorated performances (I didn't measure them but current solution can't be fast). If we need better performances then we need different approach that would deteriorate code design (less object creating, bulk copying, etc.). But I choose better design because I didn't had any non-functional requirements that would exactly tell me about needed performances.
