char alphabet[100];
char alphabet2[36];

void alphbt(int NS) {
	for (int i = 0; i < NS; i++) {
		if (i + '0' <= '9') {
			alphabet[i + '0'] = i;
		}
		else {
			alphabet[i - 10 + 'A'] = i;
		}
	}
}

void alphbt2(int NS) {
	for (int i = 0; i < NS; i++) {
		if (i + '0' <= '9') {
			alphabet2[i] = i + '0';
		}
		else {
			alphabet2[i] = i - 10 + 'A';
		}
	}
}