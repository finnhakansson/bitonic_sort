

class RainbowItem: public Item {
private:
    static unsigned char** colors;
    static int numberOfColors;
public:
    RainbowItem();
    RainbowItem(int num);
    ~RainbowItem();
    unsigned char r() const;
    unsigned char g() const;
    unsigned char b() const;
};


