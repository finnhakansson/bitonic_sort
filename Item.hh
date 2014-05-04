

class Item {
private:
    static bool randInit;
    int number;
public:
    Item();
    ~Item();
    int getNumber() const;
    bool operator>(const Item &other) const;
};


