

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
    void append(const unsigned char r, const unsigned char g, const unsigned char b);
    void insert(const unsigned char r, const unsigned char g, const unsigned char b, const unsigned int x, const unsigned int y);
    void clear();
};

