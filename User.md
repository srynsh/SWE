# [User Functions](#user-functions)
This section describes the various functionalities a user is entitled to in the web application outside the auction-room interface. The following table charts out the functions necessary to handle use-cases appropriately.

### Authentication:
| Function          | Description                                           |
| :---------------: | :---------------------------------------------------: |
| Sign Up           | Set name, username, password, contacts, interests     |
| Verify Account    | Authenicate registration or password reset            |
| Log In            | Direct user to dashboard given correct credentials    |
| Edit Profile      | Allows user to edit details of profile                |
| Forgot Password   | Allows user to reset password through contacts        |

### Dashboard:
| Function          | Description                                               |
| :---------------: | :-------------------------------------------------------: |
| Create Auction    | List items + clauses and schedule auction time            |
| Recommendations   | Provides user with auctions user might be interested in   |
| Search Options    | Allows user to search by tags, description, time, price   |
| View History      | Allows user to view completed and scheduled auctions      |
| View Other Profile| Allows user to view profiles of other users               |

## [Authentication Use-Cases](#authentication-use-cases)
### Sign Up
*Primary Agent*: User\
*Preconditions*: None\
*Main Flow*:
- User enters the website and is prompted to register themself on the website as an account if they are not registered.
- User is asked to give mandatory details such as username, password, name, email contact etc.
- User is also prompted to additional details such as mobile contact details, interests etc.
- User submits details and waits for *verification*.\
*Excpetions*:
- User chooses an already existing username. User is then prompted to choose another username.
- User sets a password which has insufficient strength. User is then prompted to choose new password.
- Both instances of password do not match. User is then prompted to recheck passwords.
- All mandatory fields have not been filled. User is then prompted to fill all mandatory fields.

### Log In
*Primary Agent*: User\
*Preconditions*: Have a registered account\
*Main Flow*:
- User enters the website and is prompted to log in if they have been registered on the website.
- User is prompted to enter username and password to log on to the website.
- If correct credentials are provided, the user is directed to their dashboard page.\
*Excpetions*:
- User enters incorrect credentials. User is then prompted to enter correct credentials.
- User forgets password and is prompted to the *forgot password* routine.

### Forgot Password
*Primary Agent*: Server\
*Preconditions*: Called when user wants to verify account after registration\
*Main Flow*:
- The server sends a message via backup contacts - email or mobile.
- The user is prompted to click on a link from the afore-mentioned contacts to reset password.
- The user is then requested to confirm new password.\
*Exceptions*:
- Both instances of password do not match. User is then prompted to recheck passwords.
- User sets a password which has insufficient strength. User is then prompted to choose new password.

### Edit Profile
*Primary Agent*: User\
*Preconditions*: User is logged in\
*Main Flow*:
- User clicks on profile details from the dashboard and chooses to edit profile details excluding username.
- User fills in new details in a form with details already filled in.
- User then submits details and profile changes are updated.\
*Exceptions*:
- Mandatory fields are not filled. User is then prompted to fill all mandatory fields.

### Verify Account
*Primary Agent*: Server\
*Preconditions*: Called when user has completed filling registration details\
*Main Flow*:
- The server sends a message via backup contacts - email or mobile.
- The user is prompted to click on a link to redirect themselves to the website's dashboard. The user is also automatically logged in.\
*Exceptions*:
- The link for verification has been timed out. User must re-register account.

## [Dashboard](#dashboard)
### Create Auction
*Primary Agent*: User\
*Preconditions*: User is logged in\
*Main Flow*:
- User chooses to create an auction and schedule it for a stipulated time.
- User is then directed to a page which prompts user to enter details of the auction in stages.
- User is first prompted to enter details for all items to be presented in the auction. Every item is provided with a name, description, relevant tags, starting price, optional clauses attached etc.
- User is then prompted to enter general details for the auction. Details include minimum increment for each bid, start-time, end-time, return policies and other clauses.
- User is finally prompted to fill a questionnaire to generate the license for the auction.\
*Exceptions*:
- Mandatory fields have not been filled. User is then prompted to fill missing mandatory fields.
- No items have been added. User is then prompted to add atleast one item in the auction.
- Time window entered has already started or passed. User is then prompted to enter a valid time-window.

### Recommendations
*Primary Agent*: Server\
*Preconditions*: User is logged in, presently at the dashboard\
*Main Flow*:
- User is shown a list of upcoming auctions which are relevant to user interests, search history, auction history etc.
- User can toggle *Number of Auctions per Page* or click on *View More* to view more auctions and their details if necessary.
- User can select one of the auctions to view details of all items listed on the auction.
- If interested and the auction is currently going on, the user can click on *Join* to enter the virtual auction-room. The user is first shown the agreement clause to join the auction. The user must also accept the agreement clause before entering the auction-room.\
*Exceptions*:
- User does not agree to the agreement clause. The user is then prompted to agree to the clauses.

### Search Options
*Primary Agent*: User\
*Preconditions*: User is logged in\
*Main Flow*:
- User is allowed to search for multiple relevant auctions by various fields. These fields include relevant tags, item description, start-time, end-time, starting prices, popularity (number of attendees) etc.
- User is then prompted to click *Search* and is then presented with a list of relevant auctions.
- User can toggle *Number of Auctions per Page* or click on *View More* to view more auctions and their details if necessary.
- User can select one of the auctions to view details of all items listed on the auction.
- If interested and the auction is currently going on, the user can click on *Join* to enter the virtual auction-room. The user is first shown the agreement clause to join the auction. The user must also accept the agreement clause before entering the auction-room.\
*Exceptions*:
- No search filter is applied. The user is then prompted to make atleast one field non-empty.
- User does not agree to the agreement clause. The user is then prompted to agree to the clauses.
- No match occurs. The user is shown text conveying there are no matches and prompts them to enter alternate key words.

### View Auction History
*Primary Agent*: User\
*Preconditions*: User is logged in\
*Main Flow*;
- User chooses to view auction history by clicking on an appropriate link from the dashboard. 
- The user is shown a list of auctions which the user has either attended or hosted.
- The user can select one of the auctions and is directed to the auction page details.
- Details include purchases made in the auction (if any), time spent on the auction date etc. (if the user participated in said auction)
- Details include purchasees, amount paid for all items sold in the auction, and other details entered by the user when the auction was scheduled.\
*Exceptions*:
- No history exists. The user is prompted to search for auctions to join or is prompted to create an auction.

### View Other Profiles
*Primary Agent*: User\
*Preconditions*: User is logged in\
*Main Flow*:
- User can access pubic profile details by clicking usernames from auction detail pages or auction history pages.
- The user can access the auctions that other users have hosted or attended.