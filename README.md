# Bulletproofs with Pedersen Commitments and Range Proofs

This project is a C++ implementation of Pedersen commitments and range proofs using the `secp256k1` cryptographic library. It includes modularized classes to handle commitments, range proofs, and public key operations. The project demonstrates the integration of `secp256k1` with custom classes to handle cryptographic tasks such as verifying range proofs.

### Installing `secp256k1`

If you don't have the `secp256k1` library installed, you can build and install it from source:

```bash
git clone https://github.com/bitcoin-core/secp256k1.git
cd secp256k1
./autogen.sh
./configure
make
sudo make install
```
### Building the Project

This project uses CMake for build configuration. Follow the steps below to build the project:

Create a build directory:

```bash
mkdir build
cd build
```

Run CMake to configure the build:

```bash
cmake ..
```
Build the project using make:

```bash
make
```
Running the Example

```bash
./bulletproofs
```

S003-1
