import basic_code

while True:
	text = input('>>> ')
	if text.strip() == "": continue
	result, error = basic_code.run('<stdin>', text)

	if error:
		print(error.as_string())
	else: 
		print(result)
		