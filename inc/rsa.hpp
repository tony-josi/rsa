
class rsa {

private:
    size_t bit_size;
public:
    rsa(size_t bit_size) { bit_size = bit_size; }
    int rsa_generate_keys();
    ~rsa();

};

