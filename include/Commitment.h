#ifndef COMMITMENT_H
#define COMMITMENT_H

#include <array>
#include <vector>
#include "Secp256k1Wrapper.h"

// Commitment class representing a Pedersen commitment
class Commitment {
public:
    static constexpr size_t COMMITMENT_SIZE = 33;  // Size of a Pedersen commitment

    // Default constructor
    Commitment();

    // Constructor from a vector of bytes
    Commitment(const std::vector<uint8_t>& data);

    // Creates a commitment from a public key
    static Commitment fromPubKey(Secp256k1Wrapper& secp, const PublicKey& pk);

    // Converts the commitment to a public key
    PublicKey toPubKey(Secp256k1Wrapper& secp) const;

    // Returns the internal commitment data
    const std::array<uint8_t, COMMITMENT_SIZE>& getData() const;

private:
    std::array<uint8_t, COMMITMENT_SIZE> data;  // Internal data of the commitment
};

#endif // COMMITMENT_H
