

class RainbowItem: public Item {
private:
    unsigned long rgb;
    unsigned long hsv2rgb(float h, float s, float v);
public:
    RainbowItem();
    RainbowItem(int num);
    ~RainbowItem();
    unsigned char r() const;
    unsigned char g() const;
    unsigned char b() const;
    void dump() const;
};


