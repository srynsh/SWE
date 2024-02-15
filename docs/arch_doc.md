---
author: "Architecture Document"
---

## [Architecture Style](#architecture-style)
Client and Server style was chosen for this architecture. It provides the following:

- **Access Time:** The server can access the database faster than in case of a distributed architecture.
- **Fault Tolerance:** The server can be designed to be fault tolerant. This cannot be enforced in a peer-to-peer style architecture.
- **Availability:** A server can be designed to be run continuously whereas this is difficult to enforce in a peer-to-peer style architecture.
- **Concurrency:** The server can bid requests from multiple clients correctly, whereas a style like repository may lead to inconsistency.
- **Fairness:** If auctioneers hosted the auctions in a peer-to-peer style, they could drop bids by certain bidders.

## [Attribute Tradeoff Analysis](#attribute-tradeoff-analysis)

|                 | Arch. 1: Client-Server | Arch. 2 Peer-|
|-----------------|----------------|----------------|
| Response Time   | Faster         | Slower         |
| Scalability     | Yes            | Yes            |
| Availability    |                |                |
| Security        |                |                |
| Concurrency     | Yes            | Yes            |
| Maintainability | Yes            | Yes            |