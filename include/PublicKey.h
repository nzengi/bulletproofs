#ifndef PUBLICKEY_H
#define PUBLICKEY_H

#include "secp256k1.h"

// PublicKey class representing a secp256k1 public key
class PublicKey {
public:
    PublicKey();
    PublicKey(const secp256k1_pubkey& pubkey);

    // Constructor from raw public key data
    PublicKey(const std::vector<uint8_t>& data);

    // Returns the internal secp256k1 public key
    const secp256k1_pubkey& getInternal() const;

private:
    secp256k1_pubkey pubkey;  // Internal secp256k1 public key
};

#endif // PUBLICKEY_H
