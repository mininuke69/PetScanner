barcodeFile = open("barcodes.txt", "r")
barcodes = barcodeFile.readlines()
barcodeFile.close()

logFile = open("log.txt", "r")
log = logFile.readlines()
logFile.close()

input = ""

while input != exit:
	input = input("Voer de EAN-13 code in")
	for barcode in barcodes:
		if barcode = input:
			print("Bien!")
			pass
	inputYN = input("Kon de code niet vinden, wil je hem toevoegen? (y/n)"
	if inputYN == "y":
		