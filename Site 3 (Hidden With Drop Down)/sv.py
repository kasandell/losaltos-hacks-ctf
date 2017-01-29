from functools import wraps
from flask import abort
from flask import request, Response
from flask import Flask, render_template
from flask_basicauth import BasicAuth



app = Flask(__name__)


app.config['BASIC_AUTH_USERNAME'] = 'danappelxx'
app.config['BASIC_AUTH_PASSWORD'] = 'country-codes'

basic_auth = BasicAuth(app)

@app.route('/')
@basic_auth.required
def secret_view():
    return render_template('site.html')

app.run()
