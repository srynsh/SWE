---
    title: Design Specifications (G3)
    author: Anshul Sangrame, Rajiv Chitale, Rishit D, Suryaansh Jain
    geometry: margin=1.5 cm
---

# Overview
## Software
Our software aims to provide an end-to-end solution for customers participating in online auctions. We provide personalized interfaces for all users taking into account their preferences and auction history. We allow prospective auctioneers to declare items and schedule auctions at their convenience. Our software provides for multiple bidders to join auction rooms, leave auction rooms and bid for items of interest.

## Design
This document encapsulates our data-flow-diagrams, their abstract inputs and outputs along with the appropriate structured charts and their comprising modules. We also specify each module type and its predicted complexity in the system in terms of cohesiveness and coupling. This document highlight possible bottlenecks and error-prone modules with intuitive reasoning and mathematical analysis. We also consider the tentative lines-of-code (LoC) for every input, transform and output subsystems./
We summarize our software through an interface sketch comprising of relevant classes, attributes, methods and inheritances.

# Data Flow Diagrams
We elucidate the data-flow of our software through the following diagrams. To simplify our data-flow and modularize our application we effectively split our software into three very loosely coupled systems - authentication, general utilities and auction-room management. We have also highlighted the most abstract inputs and outputs for each of these subsystems in their reprective diagrams.

![DFD with MAI MAO](../diagrams/dfd2-mai-mao.jpg)

# Structured Charts
We now list sequentially modules formed from the abforementioned data-flow duagrams via factoring at different levels and the final structured chart with all modules combined.

## First Level Factored Modules

![First Level Factoring](../diagrams/FirstLevelFactor.jpg)

## Factored Input Modules

![Factoring Input Modules](../diagrams/InputFactor.jpg)

## Factored Output Modules

![Factoring Output Modules](../diagrams/OutputFactor.jpg)

## Factored Transform Modules

![Factoring Central Transform Modules](../diagrams/CentralTransform.jpg)


## Final Structured Chart

![Factored Structure Chart](../diagrams/FinalSC.jpg)


# Design Analysis
## List of Modules
We list our final factored modules in the table below with corresponding type of module and cohesion, and its estimated size.

|   Module Name             |   Module Type     |   Cohesion Type       |   Estimated Size  |
| -----------------         | ----------------- | -----------------     | ----------------- |
| Decrypt+Verify Reset Link |   Input           | Functional            |                   |  
| Get New Password          |   Input           | Functional            |                   |
| Reset Password            |   Coordination    | Functional            |                   |  
| Verify Password Strength  |   Input           | Functional            |                   |
| Update Password           |   Output          | Functional            |                   | 
| Confirm Reset Status      |   Output          | Functional            |                   | 
| Get contact (email)       |   Input           | Functional            |                   |
| Send Reset Link           |   Output          | Functional            |                   | 
| Get new profile details   |   Input           | Functional            |                   |
| Get Location              |   Input           | Functional            |                   |
| Get Age                   |   Input           | Functional            |                   |
| Get Topics of Interest    |   Input           | Functional            |                   |
| Get Sign Up Details       |   Input           | Functional            |                   |
| Get Username              |   Input           | Functional            |                   |
| Get New Password          |   Input           | Functional            |                   |
| Get Contact               |   Input           | Functional            |                   |
| Sign Up                   |   Transform       | Functional            |                   |
| Check If Username Exists  |   Transform       | Functional            |                   |
| Verify Password Strength  |   Transform       | Functional            |                   |
| Check Length              |   Transform       | Functional            |                   |
| Check Symbols             |   Transform       | Functional            |                   |
| Hash Password             |   Transform       | Functional            |                   |
| Insert User Details       |   Output          | Functional            |                   | 
| Display Sign Up Status    |   Output          | Functional            |                   | 
| Send Verification email   |   Output          | Functional            |                   | 
| Get Sign-In Details       |   Input           | Functional            |                   |
| Verify Sign-In            |   Transform       | Functional            |                   |
| Hash Received Password    |   Transform       | Functional            |                   |
| Retrieve Credentials      |   Input           | Functional            |                   |
| Generate Token or Failure |   Output          | Functional            |                   | 
| Store Token in Browser    |   Output          | Functional            |                   | 
| Display Sign-In Failure   |   Output          | Functional            |                   | 



|   Module Name             |   Module Type     |   Cohesion Type       |   Estimated Size  |
| -----------------         | ----------------- | -----------------     | ----------------- |
|   Bid Main                |   Composite       | Functional            |                   |
|   Get Bid Price           |   Input           | Functional            |                   |
|   Get Auction ID (URL)    |   Input           | Functional            |                   |
|   Positive Bid            |   Transform       | Logical               |                   | **
|   Item Main               |   Composite       | Functional            |                   |
|   Get Item Name           |   Input           | Functional            |                   |
|   Get Item Tag            |   Input           | Functional            |                   |
|   Get Item Image          |   Input           | Functional            |                   | 
|   Get Item St Price       |   Input           | Functional            |                   | **
|   Get Auth Token          |   Input           | Functional            |                   | **
|   Get Auction ID (Room)   |   Input           | Functional            |                   | **
|   Get Current Time        |   Input           | Functional            |                   | **
|   Get Leaderboard (abrupt)|   Composite       | Temporal/Sequential   |                   | 
|   Query for End Auction   |   Transform       | Logical/Temporal      |                   |
|   Exec Query End Auction  |   Transform       | Logical/Temporal/Fnl  |                   | **
|   Add Item (DB)           |   Output          | Functional            |                   | **
|   Get Highest Bid         |   Composite       | Communicational/Fnl   |                   |
|   Query for Highest Bid   |   Transform       | Functional            |                   |
|   Exec Query Highest Bid  |   Transform       | Functional            |                   | **
|   Update Leaderboard      |   Composite       | Logical/Functional    |                   |
|   Check Greater User      |   Transform       | Logical/Functional    |                   |
|   Update Leaderboard Bids |   Output          | Functional            |                   | **
|   Get Username            |   Composite       | Functional            |                   |
|   Get Encryption Key      |   Input           | Functional            |                   |
|   Decrypt Token           |   Transform       | Functional            |                   | **
|   Update Interest         |   Output          | Functional            |                   | **
|   Get Leaderboard         |   Composite       | Functional            |                   |
|   Query for Leaderboard   |   Transform       | Functional            |                   |
|   Exec Leaderboard Query  |   Transform       | Functional            |                   | **
|   Get Auction Item List   |   Composite       | Functional            |                   |
|   Query for Item List     |   Transform       | Functional            |                   |
|   Exec Query for Item List|   Transform       | Functional            |                   | **
|   Display for Auction Room|   Coordination    | Functional            |                   |
|   Display Item List       |   Coordination    | Functional/Temporal   |                   |
|   Display Item            |   Output          | Functional            |                   |
|   Display Leader Board    |   Output          | Functional            |                   | **
|   Update Auction History  |   Output          | Functional            |                   | **
|   Notify Winner           |   Composite       | Functional            |                   |
|   Email Template          |   Transform       | Functional            |                   |
|   Send Email              |   Output          | Functional            |                   | **
|   Store Auction End       |   Output          | Functional            |                   | **


