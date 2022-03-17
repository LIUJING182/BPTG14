# BPTG14

This project shows the efficiency of BPTG14 for evaluating decision trees on private data.

## IDE

In the coding, we chose CLion as IDE. Therefore, if you use CLion as IDE it will help you deploy this project mor conveniently.

## Dependencies

### Install NTL

    tar -xzvf ntl-11.5.1.tar.gz
    cd ntl-11.5.1/src
    ./configure 
    make
    sudo make install

### Install HElib
https://github.com/homenc/HElib
    tar -xzvf HElib-2.2.1.tar.gz
    cd HElib-2.2.1
    mkdir build
    cd build
    make
    sudo make install
