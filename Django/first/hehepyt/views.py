from django.shortcuts import render, HttpResponse

def home (request):
    return render (request, "index.html")

def linktogc (request):
    return HttpResponse ("Link To GC : ")

def insidetcsbhediyas (request):
    return HttpResponse (" Meet Our Team : ")