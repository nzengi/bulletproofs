#include "PublicKey.h"
#include <stdexcept>

// Default constructor: Initializes an empty public key
PublicKey::PublicKey() {
    // Optionally initialize to zero or a specific invalid state
}

// Constructor from a secp256k1_pubkey object
PublicKey::PublicKey(const secp256k1_pubkey& pubkey) : pubkey(pubkey) {}

// Constructor from raw public key data
PublicKey::PublicKey(const std::vector<uint8_t>& data) {
    // Deserialize raw public key data
    if (!secp256k1_ec_pubkey_parse(secp256k1_context_create(SECP256K1_CONTEXT_VERIFY), &pubkey, data.data(), data.size())) {
        throw std::runtime_error("Failed to parse public key");
    }
}

// Returns the internal secp256k1 public key
const secp256k1_pubkey& PublicKey::getInternal() const {
    return pubkey;
}
