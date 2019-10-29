from flask import Flask, request, render_template

app = Flask(__name__)


@app.route('/', methods=["GET"])
def index():
    return render_template('main.htm')


@app.route('/test', methods=["GET"])
def test():
    #values = request.get_json()
    print(request.args)
    print(request.get_json())
    return request.args["t2"]


port = 5000
if __name__ == "__main__":
    app.run(debug=True)
