from django.shortcuts import render, redirect
from django.core.mail import send_mail
from django.contrib import messages
from decouple import config
from .forms import ContactForm

def portfolio_view(request):
    """Main portfolio page – also handles the contact form."""
    if request.method == 'POST':
        form = ContactForm(request.POST)
        if form.is_valid():
            name = form.cleaned_data['name']
            email = form.cleaned_data['email']
            phone = form.cleaned_data.get('phone', '')
            subject = form.cleaned_data.get('subject', 'No subject')
            message = form.cleaned_data['message']

            full_message = (
                f"Name: {name}\n"
                f"Email: {email}\n"
                f"Phone: {phone}\n\n"
                f"Message:\n{message}"
            )

            try:
                send_mail(
                    subject=f"Portfolio Contact: {subject}",
                    message=full_message,
                    from_email=config('EMAIL_HOST_USER'),
                    recipient_list=[config('EMAIL_HOST_USER')],
                    fail_silently=False,
                )
                messages.success(request, ' Your message has been sent successfully! I\'ll get back to you soon.')
                return redirect('portfolio')  # or the same page
            except Exception as e:
                messages.error(request, f' An error occurred: {str(e)}')
        else:
            messages.error(request, ' Please correct the errors below.')
    else:
        form = ContactForm()

    # The main portfolio template will include the form
    return render(request, 'portfolioApp/index.html', {'form': form})
    

    
def custom_404_view(request, exception):
    return render(request, 'portfolioApp/404.html', status=404)