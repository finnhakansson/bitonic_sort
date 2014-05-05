

class Bmp {
private:
    int width;
    int height;
    int pad;
    int size;
    unsigned char* data;
    int index;
    int horizontal_pos;
    void createHeader();
public:
    Bmp(int width, int height);
    ~Bmp();
    int getDataSize() const;
    unsigned char* getData(unsigned char*);
    void append(unsigned char r, unsigned char g, unsigned char b);
};

