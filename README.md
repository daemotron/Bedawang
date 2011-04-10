Bedawang TCP Server Framework
=============================

About Bedawang
--------------

In daily business, developers often need to create a solution to a problem
that has already been solved by others. One of these problems is the
implementation of a multiplexing TCP server, e. g. to create an agent or
backend for any kind of network-based software.

However, one often finds poorly implemented solutions, that either do not
scale well, or do not properly implement SSL or TLS support. Other security
issues (like format string vulnerabilities, race conditions or simply buffer
overflows) occur much more frequently than one would like to see.

This is where Bedawang jumps in. Bedawang is specialised in "only" providing
the TCP/IP stuff, network I/O, process management, multiplexing and SSL/TLS
support. So any application built atop Bedawang just can concentrate on
implementing the layer 7 protocol and the application logic.

Frequently Asked Questions
--------------------------

* What does the name Bedawang mean?
  
  > In Balinese hinduistic mythology, Bedawang Nala is the name of a huge
  > turtle carrying the world on its back. Of course I am not that fatuous,
  > thinking this project would carry the world on its back - but it can,
  > to a certain extend, carry greater, bigger and nicer projects on its
  > virtual back.