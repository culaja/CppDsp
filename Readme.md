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
[logo]: Architecture.png "Architecture picture"

# Design
    Text goes here.
# Conclusion
    Text goes here.