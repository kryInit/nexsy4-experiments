from PIL import Image

def image_to_verilog_hex(filename):
    img = Image.open(filename).resize((256, 256))
    pixels = list(img.getdata())
    verilog_data = []

    for pixel in pixels:
        # RGB値を4ビットずつに変換
        r, g, b, _ = pixel
        r = r >> 3
        g = g >> 3
        b = b >> 3
        # 上位からR,G,Bの順に12ビットデータを形成
        combined_value = (r << 11) | (b << 6) | g

        verilog_data.append(f"16'h{combined_value:03X}")

    return verilog_data

if __name__ == "__main__":
    filename = "/Users/yudai.inada/Documents/Untitled/1.png"
    verilog_array = image_to_verilog_hex(filename)

    # 100個ごとに改行を追加
    formatted_data = []
    for i in range(0, len(verilog_array), 100):
        formatted_data.append(", ".join(verilog_array[i:i+100]))

    output_string = ",\n".join(formatted_data)
    print(f"    reg [15:0] image_data [0:65535] = {{{output_string}}};")

