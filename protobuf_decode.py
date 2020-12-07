import example_pb2

if __name__ == "__main__":
	file_name = "./encoding_cpp.pbuf"
	address_book_from_file = example_pb2.AddressBook()
	with open(file_name,"rb") as f:
		address_book_from_file.ParseFromString(f.read())

	print(address_book_from_file)