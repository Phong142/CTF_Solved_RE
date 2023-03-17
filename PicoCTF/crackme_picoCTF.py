bezos_cc_secret = "A:4@r%uL`M-^M0c0AbcM-MFE0g4dd`_cgN"

alphabet = "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ"+ \
            "[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~"


def decode_secret(secret):
    #ROT47 decode

    rotate_const = 47           # Encryption key

    decoded = ""            # Storage for decoded secret
    # decode loop
    for c in secret:
        index = alphabet.find(c)
        original_index = (index + rotate_const) % len(alphabet)
        decoded = decoded + alphabet[original_index]

    print(decoded)

decode_secret(bezos_cc_secret)