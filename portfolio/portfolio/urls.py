# portfolio/urls.py
from django.urls import path, include
from portfolioApp.views import custom_404_view   # for the 404 handler

# --- Custom 404 handler (works when DEBUG=False) ---
handler404 = 'portfolioApp.views.custom_404_view'

urlpatterns = [
    # Include the app's URLs – this makes the home page available at '/'
    path('', include('portfolioApp.urls')),

    # Optional: Django admin – uncomment if needed
    # path('admin/', admin.site.urls),
]