# portfolioApp/urls.py
from django.urls import path
from . import views

app_name = 'portfolioApp'   # namespace for reversing URLs

urlpatterns = [
    # Home page – the root of the site
    path('', views.portfolio_view, name='portfolio'),
]