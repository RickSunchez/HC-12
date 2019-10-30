from flask import Flask, request, render_template
import json
from draw import *

#draw_coroners()

app = Flask(__name__)


@app.route('/', methods=["GET"])
def index():
    return render_template('main.htm')


@app.route('/coroner', methods=["GET"])
def coroner():
    lat = request.args["lat"]  # широта
    long = request.args["long"]  # долгота
    acc = request.args["acc"]  # аккуратность
    print(lat, long, acc)

    f = open("coroners.json", "r")
    coroners = json.load(f)
    coroners.append({"x": lat, "y": long, "r": acc})

    f = open("coroners.json", "w")
    json.dump(coroners, f)
    return "Концевая метка записана"


@app.route('/beacon', methods=["GET"])
def beacon():
    lat = request.args["lat"]  # широта
    long = request.args["long"]  # долгота
    acc = request.args["acc"]  # аккуратность
    print(lat, long, acc)
    return "Координаты маяка записаны"


@app.route('/favicon.ico', methods=["GET"])
def favicon():
    return "favicon is not response"


port = 5050
if __name__ == "__main__":
    app.run(host='127.0.0.1', port=port)
