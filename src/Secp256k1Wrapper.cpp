#include "Secp256k1Wrapper.h"
#include "PublicKey.h"
#include <stdexcept>

// Constructor: Create a secp256k1 context for signing and verification
Secp256k1Wrapper::Secp256k1Wrapper() {
    ctx = secp256k1_context_create(SECP256K1_CONTEXT_SIGN | SECP256K1_CONTEXT_VERIFY);
}

// Destructor: Destroy the secp256k1 context to free resources
Secp256k1Wrapper::~Secp256k1Wrapper() {
    secp256k1_context_destroy(ctx);
}

// Converts a public key to a Pedersen commitment
bool Secp256k1Wrapper::pubKeyToPedersenCommitment(std::array<uint8_t, 33>& out, const PublicKey& pk) {
    // This function requires a specific secp256k1 extension or additional logic to convert
    // a public key to a Pedersen commitment. You will need to implement or find an
    // appropriate library function to handle this conversion.
    // For now, this is a placeholder.
    return false;
}

// Converts a Pedersen commitment back to a public key
PublicKey Secp256k1Wrapper::pedersenCommitmentToPubKey(const std::array<uint8_t, 33>& commit) {
    secp256k1_pubkey pubkey;
    if (secp256k1_pedersen_commitment_to_pubkey(ctx, &pubkey, commit.data())) {
        return PublicKey(pubkey);  // Assuming PublicKey has a constructor that takes secp256k1_pubkey
    } else {
        throw std::runtime_error("Invalid public key conversion from Pedersen commitment");
    }
}

// Verifies a range proof for a given commitment
bool Secp256k1Wrapper::verifyRangeProof(const std::array<uint8_t, 33>& commit, const std::array<uint8_t, 5134>& proof, size_t proofLength) {
    uint64_t min_value, max_value;
    return secp256k1_rangeproof_verify(ctx, &min_value, &max_value, commit.data(), proof.data(), proofLength, nullptr, 0, nullptr);
}
