#include <vector>
#define uuid int
#define time int

using namespace std;
class auction {
    uuid id;
    uuid creator;
    time start_time;
    time end_time;
    int start_price;
    int current_price;
    int min_increment;
    bool visiblity;
    uuid key;
    int time_since_last_bid;
    uuid winner;
    vector<int> tags;
    string name;
    string description;
    string image;
    vector<pair<uuid, int>> bids;

    void init(int start_price, int min_increment, time start_time, time end_time, bool visiblity, uuid creator, vector<int> tags);
    int get_current_price();
    int set_current_price(int price);
    bool get_visiblity();
    bool check_key(uuid key);
};

class user {
    uuid id;
    string name;
    string email;
    string password;
    string phone;

    void init(string name, string email, string password, string phone);
    vector<uuid> get_all_created_auctions;
    vector<uuid> get_all_bidded_auctions;
    vector<uuid> generate_auctions(int count);
    uuid create_auction(int start_price, int min_increment, time start_time, time end_time, bool visiblity, vector<int> tags);
    bool bid(uuid auction_id, int price, uuid key);
    bool delete_auction(uuid auction_id);
    bool edit_name(string name);
    bool edit_email(string email);
    bool edit_password(string password);
    bool edit_phone(string phone);
};