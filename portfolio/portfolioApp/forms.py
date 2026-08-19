from django import forms

class ContactForm(forms.Form):
    name = forms.CharField(
        max_length=100,
        widget=forms.TextInput(attrs={
            'id': 'fullName',
            'placeholder': 'Enter your name',
            'required': True,
        })
    )
    email = forms.EmailField(
        widget=forms.EmailInput(attrs={
            'id': 'emailAddress',
            'placeholder': 'Enter your email',
            'required': True,
        })
    )
    phone = forms.CharField(
        required=False,
        max_length=20,
        widget=forms.TextInput(attrs={
            'id': 'contactNumber',
            'placeholder': 'Enter your contact',
        })
    )
    subject = forms.CharField(
        required=False,
        max_length=200,
        widget=forms.TextInput(attrs={
            'id': 'subjectLine',
            'placeholder': "Let's talk about...",
        })
    )
    message = forms.CharField(
        widget=forms.Textarea(attrs={
            'id': 'messageText',
            'placeholder': 'Write your message here...',
            'required': True,
        })
    )